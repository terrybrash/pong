#!/usr/bin/env -S cargo +nightly -Zscript
---
[package]
name = "pong_build"
edition = "2024"

[dependencies]
cc = "1"
---

use std::path::Path;
use std::process::{Command, ExitCode};

const USAGE: &str = "usage: cargo +nightly -Zscript tools/build.rs [run]\n  (no argument)  assemble src/pong.asm and link target/pong.exe\n  run            build, then start target/pong.exe";
const MSVC_TARGET: &str = "x86_64-pc-windows-msvc";
const SOURCE_PATH: &str = "src/pong.asm";
const TARGET_DIR: &str = "target";
const OBJECT_PATH: &str = "target/pong.obj";
const EXE_PATH: &str = "target/pong.exe";
const LINK_LIBS: [&str; 4] = ["kernel32.lib", "user32.lib", "gdi32.lib", "dwmapi.lib"];

enum BuildMode {
    BuildOnly,
    BuildAndRun,
}

fn build_mode_parse(args: &[String]) -> Result<BuildMode, String> {
    match args {
        [] => Ok(BuildMode::BuildOnly),
        [arg] if arg == "run" => Ok(BuildMode::BuildAndRun),
        _ => Err(format!("unknown arguments: {}", args.join(" "))),
    }
}

fn msvc_tool_command(tool_name: &str) -> Command {
    let tool = cc::windows_registry::find_tool(MSVC_TARGET, tool_name).unwrap_or_else(|| {
        panic!("{tool_name} not found: install the Visual Studio C++ build tools")
    });
    tool.to_command()
}

fn command_run(mut command: Command, step_name: &str) -> Result<(), String> {
    let status = command
        .status()
        .map_err(|error| format!("{step_name} did not start: {error}"))?;
    match status.success() {
        true => Ok(()),
        false => Err(format!("{step_name} failed with {status}")),
    }
}

fn build() -> Result<(), String> {
    assert!(
        Path::new(SOURCE_PATH).is_file(),
        "run from the pong folder: {SOURCE_PATH} is missing"
    );
    std::fs::create_dir_all(TARGET_DIR)
        .map_err(|error| format!("{TARGET_DIR} not made: {error}"))?;

    let mut assemble = msvc_tool_command("ml64.exe");
    assemble
        .args(["/nologo", "/c", "/Zi", "/W3", "/WX"])
        .arg(format!("/Fo{OBJECT_PATH}"))
        .arg(SOURCE_PATH);
    command_run(assemble, "ml64")?;

    let mut link = msvc_tool_command("link.exe");
    link.args([
        "/nologo",
        "/subsystem:windows",
        "/entry:main_entry",
        "/nodefaultlib",
        "/debug",
        "/incremental:no",
    ])
    .arg(format!("/out:{EXE_PATH}"))
    .arg(OBJECT_PATH)
    .args(LINK_LIBS);
    command_run(link, "link")
}

fn main() -> ExitCode {
    let args: Vec<String> = std::env::args().skip(1).collect();
    let build_mode = match build_mode_parse(&args) {
        Ok(build_mode) => build_mode,
        Err(error) => {
            eprintln!("{error}\n{USAGE}");
            return ExitCode::FAILURE;
        }
    };
    if let Err(error) = build() {
        eprintln!("{error}");
        return ExitCode::FAILURE;
    }
    match build_mode {
        BuildMode::BuildOnly => ExitCode::SUCCESS,
        BuildMode::BuildAndRun => match command_run(Command::new(EXE_PATH), "pong") {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("{error}");
                ExitCode::FAILURE
            }
        },
    }
}

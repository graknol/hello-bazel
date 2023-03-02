workspace(name = "hello-bazel")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    sha256 = "b8a1527901774180afc798aeb28c4634bdccf19c4d98e7bdd1ce79d1fe9aaad7",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.4.1/bazel-skylib-1.4.1.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.1/bazel-skylib-1.4.1.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

http_archive(
    name = "catch2",
    strip_prefix = "Catch2-3.3.2",
    urls = ["https://github.com/catchorg/Catch2/archive/v3.3.2.tar.gz"],
)

http_archive(
    name = "mongoose",
    build_file_content = """
cc_library(
    name = "mongoose",
    srcs = ["mongoose.c"],
    hdrs = ["mongoose.h"],
    includes = ["./"],
    include_prefix = "mongoose",
    visibility = ["//visibility:public"]
)
""",
    sha256 = "09d456350cca0895e52ea269a3b3c25dae2ff4cc374a9ed90867594042af2277",
    strip_prefix = "mongoose-7.9",
    urls = ["https://github.com/cesanta/mongoose/archive/7.9.tar.gz"],
)

config_setting(
    name = "release",
    values = {
        "define": "release=true",
    },
)

cc_binary(
    name = "server",
    srcs = [
        "server.cxx",
    ],
    copts = select({
        ":release": [
            "/GL",
            "/O2",
        ],
        "//conditions:default": [],
    }),
    linkopts = select({
        ":release": [
            "/LTCG",
        ],
        "//conditions:default": [],
    }),
    deps = ["@mongoose"],
)

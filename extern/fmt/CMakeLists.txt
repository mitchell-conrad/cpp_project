# Fetch fmtlib
FetchContent_Declare(
        fmtlib
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        7.0.3
)
# Adds fmt::fmt
FetchContent_MakeAvailable(fmtlib)
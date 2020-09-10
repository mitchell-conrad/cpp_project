# Testing library
FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1
)
FetchContent_MakeAvailable(catch2)
# Adds Catch2::Catch2
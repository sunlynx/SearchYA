find_library(HIREDIS_LIBRARY_DIR NAMES hiredis)
find_path(HIREDIS_INCLUDE_DIR NAMES hiredis/hiredis.h)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(hiredis REQUIRED_VARS HIREDIS_LIBRARY_DIR HIREDIS_INCLUDE_DIR)

if(HIREDIS_FOUND)
    message(STATUS "Found HIRedis binary - ${HIREDIS_LIBRARY_DIR}, HIRedis Include dir - ${HIREDIS_INCLUDE_DIR}")
else(HIREDIS_FOUND)
    message(WARNING "HIRedis not found")
endif()
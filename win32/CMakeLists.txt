include_directories(../libc/include)
aux_source_directory(. SRCS)
add_library(win32 OBJECT ${SRCS})

# Interface target that applies FERREX_SANITIZERS to everything linking it.
# ASan and TSan cannot be combined; enforce that here.

add_library(ferrex_sanitizers INTERFACE)
add_library(ferrex::sanitizers ALIAS ferrex_sanitizers)

if(FERREX_SANITIZERS)
  if("thread" IN_LIST FERREX_SANITIZERS AND "address" IN_LIST FERREX_SANITIZERS)
    message(FATAL_ERROR "ThreadSanitizer and AddressSanitizer cannot be used together")
  endif()

  list(JOIN FERREX_SANITIZERS "," _ferrex_san_list)
  message(STATUS "ferrex: sanitizers enabled: ${_ferrex_san_list}")

  set(_ferrex_san_flags
    -fsanitize=${_ferrex_san_list}
    -fno-omit-frame-pointer)          # readable stack traces

  if("undefined" IN_LIST FERREX_SANITIZERS)
    list(APPEND _ferrex_san_flags -fno-sanitize-recover=all)  # UB = test failure
  endif()

  target_compile_options(ferrex_sanitizers INTERFACE ${_ferrex_san_flags})
  target_link_options(ferrex_sanitizers INTERFACE ${_ferrex_san_flags})
endif()

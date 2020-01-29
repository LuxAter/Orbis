# ##############################################################################
# SOURCE FILES
# ##############################################################################
file(GLOB_RECURSE SOURCES "${ORBIS_SOURCE_DIR}/docs/*.md"
     "${ORBIS_SOURCE_DIR}/include/*.hpp")

set(RESOURCES
    icons/folder-open-solid.svg icons/folder-solid.svg icons/file-alt-solid.svg
    icons/arrow.svg icons/open.svg icons/closed.svg)

foreach(FILE_PATH IN LISTS SOURCES)
  set(DOXYGEN_INPUT "${DOXYGEN_INPUT} \\\n\"${FILE_PATH}\"")
endforeach()
foreach(FILE_PATH IN LISTS RESOURCES)
  set(DOXYGEN_RESOURCES
      "${DOXYGEN_RESOURCES} \\\n\"${ORBIS_SOURCE_DIR}/docs/${FILE_PATH}\"")
endforeach()
configure_file(Doxyfile.in Doxyfile @ONLY)

# ##############################################################################
# EXECUTABLES
# ##############################################################################
find_program(LESSC_EXECUTABLE lessc)

# ##############################################################################
# TARGET
# ##############################################################################
if(NOT LESSC_EXECUTABLE STREQUAL "LESS-NOTFOUND")
  add_custom_command(
    OUTPUT "${ORBIS_SOURCE_DIR}/docs/extra.css"
    COMMAND ${LESSC_EXECUTABLE} --compress ${ORBIS_SOURCE_DIR}/docs/extra.less
            > ${ORBIS_SOURCE_DIR}/docs/extra.css
    COMMENT "Generating extra.css"
    DEPENDS "${ORBIS_SOURCE_DIR}/docs/extra.less"
    VERBATIM)
endif()
add_custom_target(
  docs
  "${DOXYGEN_EXECUTABLE}"
  DEPENDS ${DOXYGEN_DEPENDS} "${ORBIS_SOURCE_DIR}/docs/extra.css"
  WORKING_DIRECTORY "${ORBIS_BINARY_DIR}/docs"
  COMMENT "Generating Doxygen documentation"
  VERBATIM)

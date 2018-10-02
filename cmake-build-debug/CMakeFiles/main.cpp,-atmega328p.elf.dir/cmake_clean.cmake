file(REMOVE_RECURSE
  "main.cpp,-atmega328p.map"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/main.cpp,-atmega328p.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

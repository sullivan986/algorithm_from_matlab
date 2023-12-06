aux_source_directory(Quinticpolytraj quinticpolytraj_src)

add_library(matlab_algorithm INTERFACE 
${quinticpolytraj_src}
)

target_include_directories(matlab_algorithm INTERFACE 
Quinticpolytraj
)
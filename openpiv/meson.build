openpiv_src = [
    'core/size.cpp',
    'core/rect.cpp',
    'core/util.cpp',
    'loaders/image_loader.cpp',
    'loaders/pnm_image_loader.cpp',
    'loaders/tiff_image_loader.cpp',
    libtiff_cpp_include
]

cpp_args = [
  '-D_USE_MATH_DEFINES',
  '-D_EXPORT_DLL_SYMBOLS'
]

if cxx_compiler == 'gcc'
  cpp_args += ['-export-symbols']
endif

openpiv_lib = shared_library(
  'openpivcore',
  openpiv_src,
  include_directories: [openpiv_include, pocketfft_include],
  dependencies: libopenpivcore_deps,
  cpp_args: cpp_args,
  install: true
)
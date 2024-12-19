project('cutils', 'c', default_options : ['c_std=c99'])

src = ['src/vector.c']

install_headers('include/vector.h', subdir : 'cutils')

cutils = library('cutils', src, install : true)

executable('cutils_test', sources : ['main.c'], link_with : cutils)
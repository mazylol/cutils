project('cutils', 'c', default_options : ['c_std=c99'])

src = ['src/structures/linkedlist.c', 'src/structures/vector.c']

install_headers('include/structures/linkedlist.h', 'include/structures/vector.h', subdir : 'cutils/structures')

cutils = library('cutils', src, install : true)

executable('cutils_test', sources : ['main.c'], link_with : cutils)
project('sunflower', 'c',
  version : '0.1',
  default_options : ['warning_level=3', 'c_std=c17'])

munit = dependency('munit', fallback : ['munit', 'munit_dep'])

src = ['sunflower.c', 'src/lex.c', 'src/lex.h']
exe = executable('sunflower', src, install : true)

test('basic', exe)

lex_tests_src = ['tests/lex_tests.c', 'src/lex.c', 'src/lex.h']
lex_tests_exe = executable('lex_tests', lex_tests_src, dependencies: [munit])
test('lex_tests', lex_tests_exe)

parse_tests_src = ['tests/parse_tests.c', 'src/parse.c', 'src/parse.h']
parse_tests_exe = executable('parse_tests', parse_tests_src, dependencies: [munit])
test('parse_tests', parse_tests_exe)

mir_tests_src = ['tests/mir_tests.c', 'src/mir.c', 'src/mir.h']
mir_tests_exe = executable('mir_tests', mir_tests_src, dependencies: [munit])
test('mir_tests', mir_tests_exe)

compile_tests_src = ['tests/compile_tests.c', 'src/compile.c', 'src/compile.h']
compile_tests_exe = executable('compile_tests', compile_tests_src, dependencies: [munit])
test('compile_tests', compile_tests_exe)

hashtable_tests_src = ['tests/hashtable_tests.c', 'src/hashtable.c', 'src/hashtable.h']
hashtable_tests_exe = executable('hashtable_tests', hashtable_tests_src, dependencies: [munit])
test('hashtable_tests', hashtable_tests_exe)
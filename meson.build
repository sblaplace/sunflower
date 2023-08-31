project('sunflower', 'c',
  version : '0.1',
  default_options : ['warning_level=3', 'c_std=c17'])

munit = dependency('munit', fallback : ['munit', 'munit_dep'])

src = ['sunflower.c', 'src/lex.c', 'src/lex.h']
exe = executable('sunflower', src, install : true)

test('basic', exe)

lex_tests_src = ['tests/lex_tests.c', 'src/lex.c', 'src/lex.h']
lex_tests_exe = executable('tests', lex_tests_src, dependencies: [munit])
test('lex_tests', lex_tests_exe)
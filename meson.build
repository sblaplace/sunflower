project('sunflower', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

munit = dependency('munit', fallback : ['munit', 'munit_dep'])

src = ['sunflower.c', 'src/lex.c']
exe = executable('sunflower', src,
  install : true)

test('basic', exe)

lex_tests_src = ['tests/lextests.c', 'src/lex.c']
lex_tests_exe = executable('lextests', lex_tests_src, dependencies: [munit])
test('lex test', lex_tests_exe)
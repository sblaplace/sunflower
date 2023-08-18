project('sunflower', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

exe = executable('sunflower', 'sunflower.c',
  install : true)

test('basic', exe)

lex_tests_exe = executable('lextests', 'tests/lextests.c')
test('lex test', exe)
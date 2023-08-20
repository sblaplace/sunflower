project('sunflower', 'c',
  version : '0.1',
  default_options : ['warning_level=3', 'c_std=c17'])

flex = find_program('flex')
bison = find_program('bison')

lgen = generator(flex,
output : '@PLAINNAME@.yy.c',
arguments : ['-o', '@OUTPUT@', '@INPUT@'])

lfiles = lgen.process('lexer.l')

pgen = generator(bison,
output : ['@BASENAME@.tab.c', '@BASENAME@.tab.h'],
arguments : ['@INPUT@', '--defines=@OUTPUT1@', '--output=@OUTPUT0@'])

pfiles = pgen.process('parser.y')

munit = dependency('munit', fallback : ['munit', 'munit_dep'])

src = ['sunflower.c']
exe = executable('sunflower', src, lfiles, pfiles,
  install : true)

test('basic', exe)

lex_tests_src = ['tests/tests.c']
lex_tests_exe = executable('tests', lex_tests_src, dependencies: [munit])
test('test', lex_tests_exe)
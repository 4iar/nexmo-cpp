project('nexmo-cpp', 'cpp', default_options : ['cpp_std=c++11'])

gtest = dependency('gtest')
gmock = dependency('gmock')
curlpp = dependency('curlpp')
nlohmann_json_sp = subproject('nlohmann_json')

clientsrc = [
    'client/post.cpp'
]
client = shared_library('client', clientsrc, dependencies: [ curlpp ], cpp_args: '-fPIC')

nexmosrc = [
   'nexmo/send_sms.cpp'
]
nexmo = shared_library('nexmo', nexmosrc, link_with: client, dependencies: nlohmann_json_sp.get_variable('nlohmann_json_dep'))

testsrc = [
    '../test/nexmo.test.cpp',
    '../test/nexmo/send_sms.test.cpp'
]

e = executable('tests', testsrc, link_with: nexmo, dependencies: [ gtest, gmock, nlohmann_json_sp.get_variable('nlohmann_json_dep')],  cpp_args : '-fPIC', )
test('tests', e)
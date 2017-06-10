project('nexmo-cpp', 'cpp')

gtest = dependency('gtest')
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

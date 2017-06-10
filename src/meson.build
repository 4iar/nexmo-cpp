project('nexmo-cpp', 'cpp')

gtest = dependency('gtest')
nlohmann_json_sp = subproject('nlohmann_json')


nexmosrc = [
   'nexmo/send_sms.cpp'
]
nexmo = shared_library('nexmo', nexmosrc, link_with: client, dependencies: nlohmann_json_sp.get_variable('nlohmann_json_dep'))

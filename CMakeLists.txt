cmake_minimum_required (VERSION 2.6)

project(msa_daemon_client LANGUAGES CXX)

add_library(msa_daemon_client include/msa/client/service_client.h include/msa/client/account.h include/msa/client/service_launcher.h src/service_client.cpp include/msa/client/security_scope.h include/msa/client/token.h src/token.cpp include/msa/client/legacy_token.h include/msa/client/compact_token.h)
target_include_directories(msa_daemon_client PUBLIC include/)
target_link_libraries(msa_daemon_client simpleipc logger base64 daemon_client_utils)
file(READ ${resources_dir}/test_files.tar.gz TEST_DATA_TGZ HEX)
file(READ ${resources_dir}/test_files/data/.content TEST_DATA_CONTENT HEX)

configure_file(${src_in} ${src_out} @ONLY)

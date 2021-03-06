#
# ./configure --has-posix
#

posix_prefix := posix
INC += -I$(posix_root)

posix: posix_bits																\
       posix_mmap																\
       posix_restrict														\
       posix_sysconf														\
       posix_tmp

posix_test: posix_bits_test											\
            posix_mmap_test											\
            posix_restrict_test									\
            posix_sysconf_test									\
            posix_tmp_test


# bits
posix_bits_binout := $(bin_path)$(posix_prefix)_bits$(bin_ext)

posix_bits: $(posix_bits_binout)
posix_bits_test: posix_bits
	$(posix_bits_binout)

$(posix_bits_binout): $(posix_root)bits_test.c
	$(CC) $(CFLAGS) $(INC) $^ $(bin_out)$@

# msvc on Windows
ifeq ($(CC_NAME), msvc)
posix: posix_getopt
posix_getopt: $(src_path)getopt.h $(src_path)getopt.c
posix_getopt_repo = https://raw.githubusercontent.com/alex85k/wingetopt/master/src/

$(src_path)getopt.h: 
	curl -sLo $@ $(io_getopt_repo)getopt.h
$(src_path)getopt.c:
	curl -sLo $@ $(io_getopt_repo)getopt.c
endif # end of msvc

# mmap
posix_mmap_read_binout := $(bin_path)$(posix_prefix)_mmap_read$(bin_ext)
posix_mmap_shared_binout := $(bin_path)$(posix_prefix)_mmap_shared$(bin_ext)

posix_mmap: posix_mmap_read											\
            posix_mmap_shared
posix_mmap_test: posix_mmap_read_test						\
                 posix_mmap_shared_test

posix_mmap_read: $(posix_mmap_read_binout)
posix_mmap_read_test: posix_mmap_read
	$(posix_mmap_read_binout) $(CURDIR)/src/posix/mmap/dout.random 2048

posix_mmap_shared: $(posix_mmap_shared_binout)
posix_mmap_shared_test: posix_mmap_shared
	$(posix_mmap_shared_binout) $(CURDIR)/src/posix/mmap/dout.random 2048

$(posix_mmap_read_binout): $(posix_root)mmap/read.c		\
                           $(posix_root)mmap/_mmap_.h
	$(CC) $(CFLAGS) $(INC) $< $(bin_out)$@

$(posix_mmap_shared_binout): $(posix_root)mmap/shared.c	\
                             $(posix_root)mmap/_mmap_.h
	$(CC) $(CFLAGS) $(INC) $< $(bin_out)$@

# restrict
# !TODO

# sysconf
posix_sysconf_binout := $(bin_path)$(posix_prefix)_sysconf$(bin_ext)

posix_sysconf: $(posix_sysconf_binout)
posix_sysconf_test: posix_sysconf
	$(posix_sysconf_binout)

$(posix_sysconf_binout): $(posix_root)sysconf/c1.c
	$(CC) $(CFLAGS) $(INC) $< $(bin_out)$@

# tmp
posix_tmp_binout := $(bin_path)$(posix_prefix)_tmp$(bin_ext)

posix_tmp: $(posix_tmp_binout)
posix_tmp_test: posix_tmp
	$(posix_tmp_binout)

$(posix_tmp_binout): $(posix_root)tmp/tmp.c
	$(CC) $(CFLAGS) $(INC) $^ $(bin_out)$@


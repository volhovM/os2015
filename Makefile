build: lib/libhelpers.so cat/cat

lib/libhelpers.so cat/cat:
	$(MAKE) -C $(dir $@)

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C cat clean

rebuild: clean build

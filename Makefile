build: lib/libhelpers.so lib/libbufio.so cat/cat revwords/revwords \
	lenwords/lenwords filter/filter bufcat/bufcat buffilter/buffilter

lib/libhelpers.so lib/libbufio.so cat/cat revwords/revwords lenwords/lenwords filter/filter bufcat/bufcat buffilter/buffilter:
	$(MAKE) -C $(dir $@)

clean:
	$(MAKE) -C lib clean
	$(MAKE) -C cat clean
	$(MAKE) -C revwords clean
	$(MAKE) -C filter clean
	$(MAKE) -C bufcat clean
	$(MAKE) -C buffilter clean
	$(MAKE) -C lenwords clean

rebuild: clean build

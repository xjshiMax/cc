.PHONY: output-cpp output-java

cpp: math_demo.bidl address.bidl output-cpp
	../../bidl2sl/bidl2sl *.bidl
	$(MAKE) -C cpp

java: math_demo.bidl address.bidl output-java
	../../bidl2sl/bidl2sl *.bidl -g java
	cd java && ant && cd -

clean:
	rm -rf output-cpp output-java
	$(MAKE) -C cpp clean
	cd java && ant clean && cd -

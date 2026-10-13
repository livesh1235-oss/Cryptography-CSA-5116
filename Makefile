all:
	$(MAKE) -C "LAB OBSERVATION"
	$(MAKE) -C "CO1_AT1"
	$(MAKE) -C "CO1_AT2"

clean:
	$(MAKE) -C "LAB OBSERVATION" clean
	$(MAKE) -C "CO1_AT1" clean
	$(MAKE) -C "CO1_AT2" clean

.PHONY: all clean

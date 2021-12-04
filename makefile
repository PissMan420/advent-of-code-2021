day-1-files = day-1/day-1.c
day-1-o = $(day-1-files:.c=.o)
shared-code = shared/fs.c

build_day_1:
	gcc -o build/day-1 $(day-1-files) $(shared-code) -lcurl -Wall

build_shared:
	gcc -o shared/http shared/http.c

.PHONY: build_day_1 build_shared

clean:
	rm -f build/day-1

.PHONY: clean
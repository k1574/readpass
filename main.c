#include <aes.h>
#include <unistd.h>

char *argv0;

int
main(int argc, char *argv[])
{
	int n;
	char buf[512];
	char *pbuf = buf ;

	aes_reset_term();
	aes_disable_input_echo();
	aes_apply_term_settings();

	while(n = read(0, pbuf, 1) && *pbuf != '\n')
		++pbuf;
	*pbuf = 0 ;
	aes_printf("%s", buf);

	aes_reset_term();
	aes_apply_term_settings();
	return 0 ;
}

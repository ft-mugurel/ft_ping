

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
		return 1;
	}

	// Initialize the ping operation
	ft_ping(argv[1]);

	return 0;
}

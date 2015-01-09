void prp_error(const char *str)
{
    fprintf(stderr, "\x1b[31;1m%s\x1b[0m\n", str);
}

void prp_success(const char *str)
{
    fprintf(stderr, "\x1b[32;1m%s\x1b[0m\n", str);
}

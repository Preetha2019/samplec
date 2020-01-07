FILEONE.C void sixchr1234567(void);
void sixchr1234567(void);
int main()
{
    sixchr1234567();
    sixchr12345678(); /* Will be unresolved external if more than */
                      /* 13 characters are significant. */
}
FILETWO.C void sixchr1234567()
{
    return;
}

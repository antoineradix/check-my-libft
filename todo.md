# Todo

- test all functions
- be able to test a single function (make "strlen" then send as argv to my main.c in my Makefile)

```C
  str = (char *)malloc(sizeof(char) * 10);
    expected_str = (char *)malloc(sizeof(char) * 10);

    if (!str || !expected_str)
    {
        perror("Memory allocation failed");
        free(str);
        free(expected_str);
        return;
    }
```

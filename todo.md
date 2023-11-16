# Todo

- test all functions
- be able to test a single function
- make malloc safe and clean such as:

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

- free allocated memory
- cleaner way to test segfault ?
- number the tests
- make reusable func to compare result and test crash

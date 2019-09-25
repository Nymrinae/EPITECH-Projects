int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        if  (s1[i] != s2[j]) {
            return (s1[i] - s2[j]);
        }
        i++;
        j++;
    }
}
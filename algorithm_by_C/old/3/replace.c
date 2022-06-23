/**
*    author:  shosei
*    created: 31.05.2021 00:11:38
**/
#include <stdio.h>
#include <string.h>

char *search(char *text, char *key)
{
  int m, n;
  char *p;
  m = strlen(text);
  n = strlen(key);

  for (p = text; p < text + m - n; p++)
  {
    if (strncmp(p, key, n) == 0)
    {
      return p;
    }
  }
  return NULL;
}

void replace(char *text, char *key, char *rep)
{
  char *p, buf[128];
  p = search(text, key);
  while (p != NULL)
  {
    *p = '\0';
    strcpy(buf, p + strlen(key));
    strcat(text, rep);
    strcat(text, buf);
    p = search(p + strlen(rep), key);
  }
}

int main()
{
  int k = 0;
  static char text[][128] = {"     --- 繧ｵ繝ｫ繝薙い縺ｮ闃ｱ ---",
                             "縺・▽繧ゅ＞縺､繧よ昴▲縺ｦ縺・,
                             "繧ｵ繝ｫ繝薙い縺ｮ闃ｱ繧偵≠縺ｪ縺溘・驛ｨ螻九・荳ｭ縺ｫ",
                             "謚輔￡蜈･繧後◆縺上※",
                             "縺昴＠縺ｦ蜷帙・繝吶ャ繝峨↓",
                             "繧ｵ繝ｫ繝薙い縺ｮ邏・＞闃ｱ縺励″縺､繧√※",
                             "蜒輔・蜷帙ｒ豁ｻ縺ｬ縺ｾ縺ｧ謚ｱ縺阪＠繧√※縺・ｈ縺・→",
                             ""};

  while (text[k][0] != '\0')
  {
    replace(text[k], "繧ｵ繝ｫ繝薙い", "sana");
    printf("%s\n", text[k]);
    k++;
  }
  return 0;
}

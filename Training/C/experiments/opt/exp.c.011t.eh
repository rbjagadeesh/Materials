
;; Function main (main, funcdef_no=0, decl_uid=1824, cgraph_uid=0)

main ()
{
  int d;
  float div;
  int sum;
  int c;
  int b;
  int a;
  int D.1837;
  int D.1834;

  a = 10;
  b = 20;
  c = 30;
  d = a;
  sum = a + b;
  D.1834 = c / d;
  div = (float) D.1834;
  <D.1832>:
  if (sum == c) goto <D.1835>; else goto <D.1836>;
  <D.1835>:
  __builtin_puts (&"No optimisation"[0]);
  <D.1836>:
  goto <D.1832>;
  D.1837 = 0;
  goto <D.1838>;
  <D.1838>:
  return D.1837;
}



ENTRY(main)

SECTIONS
{
  . += 1K;
  symbol = .;
  . += 1K;
  symbol2 = .;
  . += 1024K;
  symbol3 = ALIGN(13);
}
INSERT BEFORE .text;
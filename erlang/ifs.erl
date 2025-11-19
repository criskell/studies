-module(ifs).
-compile(export_all).

help_me(Animal) ->
  Talk = if Animal == cat -> "meow";
            Animal == beef -> "mooo";
            Animal == dog -> "bark";
            Animal == tree -> "tree";
            true -> "unknown"
          end,
  {Animal, "says " ++ Talk ++ "!"}.
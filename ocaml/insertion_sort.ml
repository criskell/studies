let rec insert x = function
  | [] -> [x]
  | y :: ys as lst ->
    if x <= y then x :: lst
    else y :: insert x ys

let insertion_sort lst =
  List.fold_right insert lst []

let () =
  let sorted = insertion_sort [5; 3; 1; 10] in
  List.iter (fun x -> Printf.printf "%d " x) sorted;
  print_newline ()
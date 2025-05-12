let initial_board = [|
  [|' '; ' '; ' '|];
  [|' '; ' '; ' '|];
  [|' '; ' '; ' '|];
|]

let print_board board =
  Array.iter (fun row ->
    Printf.printf "| %c | %c | %c |\n" row.(0) row.(1) row.(2)
  )
  board

let check_winner board =
  let check_line a b c =
    a = b && b = c && a <> ' '
  in
  let winner_row =
    Array.find_map (fun row ->
      if check_line row.(0) row.(1) row.(2) then Some row.(0) else None
    ) board
  in
  match winner_row with
  | Some w -> Some w
  | None ->
      let winner_col =
        Array.find_map (fun i ->
          if check_line board.(0).(i) board.(1).(i) board.(2).(i)
          then Some board.(0).(i)
          else None
        ) [|0; 1; 2|]
      in
      match winner_col with
      | Some w -> Some w
      | None ->
        if check_line board.(0).(0) board.(1).(1) board.(2).(2) then Some board.(0).(0)
        else if check_line board.(0).(2) board.(1).(1) board.(2).(0) then Some board.(0).(2)
        else None

let draw_move board player row col =
  if board.(row).(col) = ' ' then
    board.(row).(col) <- player
  else
    print_endline "Jogada inválida! Tente novamente."

let is_draw board =
  Array.for_all (fun row -> Array.for_all (fun cell -> cell <> ' ') row) board

let rec play_game board current_player =
  print_board board;

  Printf.printf "Jogador %c, escolha sua jogada (linha e coluna): " current_player;
  let row = read_int () in
  let col = read_int () in

  draw_move board current_player row col;

  match check_winner board with
  | Some winner ->
      print_board board;
      Printf.printf "Jogador %c venceu!\n" winner;
  | None ->
      if is_draw board then
        print_endline "Empate!"
      else
        let next_player = if current_player = 'X' then 'O' else 'X' in
        play_game board next_player

let () =
    play_game initial_board 'X'
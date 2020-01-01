let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;

let (||>) f g x = g(f(x));;

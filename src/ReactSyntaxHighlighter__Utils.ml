let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;

let (||>) f g x = g(f(x));;

module JsUnsafe = struct
  type t;;

  external make : 'a -> t = "%identity";;
end

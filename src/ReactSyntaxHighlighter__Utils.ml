let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;

module JsUnsafe = struct
  type t;;

  external make : 'a -> t = "%identity";;
end

module LineProps = struct
  type t =
    [ `Factory of int -> ReactDOMRe.props
    | `Plain of ReactDOMRe.props
    ]
  ;;

  let make (value : t) =
    match value with
    | `Factory propsFactory -> JsUnsafe.make propsFactory
    | `Plain plainProps -> JsUnsafe.make plainProps
  ;;
end

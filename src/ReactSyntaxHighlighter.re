[@bs.module "react-syntax-highlighter"] [@react.component]
external make:
 (
  ~language: string=?,
  ~children: string
 ) => React.element = "default";


let makeProps = (
  ~language=?,
  ~children
 ) => makeProps(
  ~language?,
  ~children=children
);

module Jsx2 = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make =
    (
      ~language=?,
      children,
    ) => ReasonReactCompat.wrapReactForReasonReact(
      make,
      makeProps(
        ~language?,
        ~children,
        (),
      ),
      children,
    );
};

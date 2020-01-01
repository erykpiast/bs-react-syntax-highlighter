open ReactSyntaxHighlighter__Utils;

module Style = ReactSyntaxHighlighter__Hljs__Style;

module Language = ReactSyntaxHighlighter__Hljs__Language;

module Element = {
  type t = Js.t({
    .
    properties: ReactDOMRe.props,
    [@bs.as "type"] type_: string,
    tagName: string,
    value: string,
    children: list(t)
  });
}

module Renderer = {
  module Input = {
    type t = Js.t({
      .
      rows: list(Element.t),
      stylesheet: ReactSyntaxHighlighter__Hljs__Style.t,
      useInlineStyles: bool,
    });
  };

  type t = Input.t => React.element;
};

[@bs.module "react-syntax-highlighter"] [@react.component]
external make:
 (
  ~language: string=?,
  ~style: ReactSyntaxHighlighter__Hljs__Style.t=?,
  ~customStyle: ReactDOMRe.style=?,
  ~codeTagProps: ReactDOMRe.props=?,
  ~useInlineStyles: bool=?,
  ~showLineNumbers: bool=?,
  ~startingLineNumber: int=?,
  ~lineNumberContainerProps: ReactDOMRe.props=?,
  ~lineNumberProps: ReactDOMRe.props=?,
  ~wrapLines: bool=?,
  ~lineProps: ReactDOMRe.props=?,
  ~renderer: Renderer.t=?,
  ~_PreTag: React.element=?,
  ~_CodeTag: React.element=?,
  ~className: string=?,
  ~children: string
 ) => React.element = "default";

let makeProps = (
  ~language=?,
  ~style=?,
  ~customStyle=?,
  ~codeTagProps=?,
  ~useInlineStyles=?,
  ~showLineNumbers=?,
  ~startingLineNumber=?,
  ~lineNumberContainerProps=?,
  ~lineNumberProps=?,
  ~wrapLines=?,
  ~lineProps=?,
  ~renderer=?,
  ~_PreTag=?,
  ~_CodeTag=?,
  ~className=?,
  ~children
 ) => makeProps(
  ~language=?(language <$> ReactSyntaxHighlighter__Hljs__Language.toString),
  ~style?,
  ~customStyle?,
  ~codeTagProps?,
  ~useInlineStyles?,
  ~showLineNumbers?,
  ~startingLineNumber?,
  ~lineNumberContainerProps?,
  ~lineNumberProps?,
  ~wrapLines?,
  ~lineProps?,
  ~renderer?,
  ~_PreTag?,
  ~_CodeTag?,
  ~className?,
  ~children
);

module Jsx2 = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make =
    (
      ~language=?,
      ~style=?,
      ~customStyle=?,
      ~codeTagProps=?,
      ~useInlineStyles=?,
      ~showLineNumbers=?,
      ~startingLineNumber=?,
      ~lineNumberContainerProps=?,
      ~lineNumberProps=?,
      ~wrapLines=?,
      ~lineProps=?,
      ~renderer=?,
      ~_CodeTag=?,
      ~_PreTag=?,
      ~className=?,
      children,
    ) => ReasonReactCompat.wrapReactForReasonReact(
      make,
      makeProps(
        ~language?,
        ~style?,
        ~customStyle?,
        ~codeTagProps?,
        ~useInlineStyles?,
        ~showLineNumbers?,
        ~startingLineNumber?,
        ~lineNumberContainerProps?,
        ~lineNumberProps?,
        ~wrapLines?,
        ~lineProps?,
        ~renderer?,
        ~_CodeTag?,
        ~_PreTag?,
        ~className?,
        ~children,
        (),
      ),
      children,
    );
};

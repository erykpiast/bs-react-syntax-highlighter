open ReactSyntaxHighlighter__Utils;

module Style = ReactSyntaxHighlighter__Hljs__Style;

module Language = ReactSyntaxHighlighter__Hljs__Language;

module Renderer = CommonRenderer(Style);

[@bs.module "react-syntax-highlighter"] [@react.component]
external make:
 (
  ~language: string=?,
  ~style: Style.t=?,
  ~customStyle: ReactDOMRe.style=?,
  ~codeTagProps: ReactDOMRe.props=?,
  ~useInlineStyles: bool=?,
  ~showLineNumbers: bool=?,
  ~startingLineNumber: int=?,
  ~lineNumberContainerProps: ReactDOMRe.props=?,
  ~lineNumberProps: ReactDOMRe.props=?,
  ~wrapLines: bool=?,
  ~lineProps: JsUnsafe.t=?,
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
  ~language=?(language <$> Language.toString),
  ~style?,
  ~customStyle?,
  ~codeTagProps?,
  ~useInlineStyles?,
  ~showLineNumbers?,
  ~startingLineNumber?,
  ~lineNumberContainerProps?,
  ~lineNumberProps?,
  ~wrapLines?,
  ~lineProps=?(lineProps <$> LineProps.make),
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

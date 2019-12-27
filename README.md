# bs-react-syntax-highlighter

[![Build Status](https://travis-ci.org/erykpiast/bs-react-syntax-highlighter.svg?branch=master)](https://travis-ci.org/erykpiast/bs-react-syntax-highlighter)
[![dependencies Status](https://david-dm.org/erykpiast/bs-react-syntax-highlighter/status.svg)](https://david-dm.org/erykpiast/bs-react-syntax-highlighter)
[![Greenkeeper badge](https://badges.greenkeeper.io/erykpiast/bs-react-syntax-highlighter.svg)](https://greenkeeper.io/)

ReasonML bindings for [react-syntax-highlighter](https://github.com/conorhastings/react-syntax-highlighter) library.

## Installation

```
npm i --save bs-react-syntax-highlighter react-syntax-highlighter
```

Then add `bs-react-syntax-highlighter` as a dependency to `bsconfig.json`.

## Usage

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter
    language="javascript">
    {"A code to highlight" |> React.string}
  </ReactSyntaxHighlighter>;
};
```

### JSX 2

The package provides fallback for projects using older version of JSX syntax.

```reasonml
let component = ReasonReact.statelessComponent("Demo");

let make = () => {
  ...component,
  render: (_self) => {
    <ReactSyntaxHighlighter.Jsx2
      language="javascript">
      {"A code to highlight" |> ReasonReact.string}
    </ReactSyntaxHighlighter.Jsx2>;
  }
};
```

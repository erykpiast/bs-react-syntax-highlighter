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

Unlike in the JavaScript counterpart, there is no default highlighter - you have to choose Hljs or Prism explicitly.

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Prism style={ReactSyntaxHighlighter.Prism.Style.darcula}>
    {"A code to highlight"}
  </ReactSyntaxHighlighter.Prism>;
};
```

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Hljs language={`JavaScript}>
    {"const foo = () => {};"}
  </ReactSyntaxHighlighter.Hljs>;
};
```

### JSX 2

The package provides fallback for projects using older version of JSX syntax.

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Hljs.Jsx2 language={`JavaScript}>
    ...{"const foo = () => {};"}
  </ReactSyntaxHighlighter.Hljs.Jsx2>;
};
```

## Notes

An **async build** and a **light build** are not currently supported. PRs are welcome!

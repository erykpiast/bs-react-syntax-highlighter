open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("jsx3", () => {
  test("empty", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs>
      {""}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { },
        '')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("language", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs language={`JavaScript}>
      {"const foo = () => {};"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { language: 'javascript' },
        'const foo = () => {};')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("style", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs style={ReactSyntaxHighlighter.Hljs.Style.darcula}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { style: require('react-syntax-highlighter/dist/esm/styles/hljs').darcula },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("renderer", () => {
    let renderer: ReactSyntaxHighlighter.Hljs.Renderer.t = (input) => {
      let theFirstRow = List.nth(input##rows, 0);
      let theFirstElement = List.nth(theFirstRow##children, 0);
      let textNode = List.nth(theFirstElement##children, 0);
      let text = textNode##value;

      text |> React.string;
    };
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs renderer>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    ) |> Enzyme.shallow;
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { renderer: (props) => props.rows[0].children[0].children[0].value },
        'foobar')
    "] |> Enzyme.shallow;

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("pre tag", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs _PreTag={<span />}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { PreTag: require('react').createElement('span') },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("className", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs className={"foo"}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { className: 'foo' },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });
});

[@bs.config {jsx: 2}];

open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("jsx2", () => {
  test("empty", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Prism.Jsx2>
      ...{""}
      </ReactSyntaxHighlighter.Prism.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').Prism,
        { },
        '')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("language", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Prism.Jsx2 language={`JavaScript}>
      ...{"const foo = () => {};"}
      </ReactSyntaxHighlighter.Prism.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').Prism,
        { language: 'javascript' },
        'const foo = () => {};')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("style", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Prism.Jsx2 style={ReactSyntaxHighlighter.Prism.Style.darcula}>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Prism.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').Prism,
        { style: require('react-syntax-highlighter/dist/esm/styles/prism').darcula },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("renderer", () => {
    let renderer: ReactSyntaxHighlighter.Prism.Renderer.t = (input) => {
      let theFirstRow = List.nth(input##rows, 0);
      let theFirstElement = List.nth(theFirstRow##children, 0);
      let textNode = List.nth(theFirstElement##children, 0);
      let text = textNode##value;

      text |> React.string;
    };
    let reasonComponent = (
      <ReactSyntaxHighlighter.Prism.Jsx2 renderer>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Prism.Jsx2>
    ) |> Enzyme.shallow;
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').Prism,
        { renderer: (props) => props.rows[0].children[0].children[0].value },
        'foobar')
    "] |> Enzyme.shallow;

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("pre tag", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Prism.Jsx2 _PreTag={<span />}>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Prism.Jsx2>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').Prism,
        { PreTag: require('react').createElement('span') },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });
});
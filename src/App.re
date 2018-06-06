type state = {repoData: option(RepoData.repo)};
type action =
  | Loaded(RepoData.repo);

let component = ReasonReact.reducerComponent("App");

let str = ReasonReact.string;
let dummyRepo: RepoData.repo = {
  stargazers_count: 27,
  full_name: "jsdf/reason-react-hacker-news",
  html_url: "https://github.com/jsdf/reason-react-hacker-news",
};

let make = children => {
  ...component,
  initialState: () => {repoData: None},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  render: ({state: {repoData}, send}) => {
    let loadReposButton =
      <button onClick=(e => send(Loaded(dummyRepo)))>
        (str("Load Repos"))
      </button>;

    let repoItem =
      switch (repoData) {
      | Some(repo) => <RepoItem repo />
      | None => loadReposButton
      };
    <div className="App"> <h1> (str("Reason Projects")) </h1> repoItem </div>;
  },
};

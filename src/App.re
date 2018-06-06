type state = {repoData: option(array(RepoData.repo))};
type action =
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

let str = ReasonReact.string;
let dummyRepos: array(RepoData.repo) = [|
  RepoData.parseRepoJson(
    Js.Json.parseExn(
      {js|
        {
          "stargazers_count": 93,
          "full_name": "reasonml/reason-tools",
          "html_url": "https://github.com/reasonml/reason-tools"
        }
    |js},
    ),
  ),
|];

let make = children => {
  ...component,
  initialState: () => {repoData: None},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  render: ({state: {repoData}, send}) => {
    let loadReposButton =
      <button onClick=(_e => send(Loaded(dummyRepos)))>
        (str("Load Repos"))
      </button>;

    let repoItems =
      switch (repoData) {
      | Some(repos) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo />,
            repos,
          ),
        )
      | None => loadReposButton
      };
    <div className="App">
      <h1> (str("Reason Projects")) </h1>
      repoItems
    </div>;
  },
};

using Avalonia;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Markup.Xaml;
using AvaloniaFrontend.Services;
using AvaloniaFrontend.ViewModels;
using AvaloniaFrontend.Views;
using Core;

namespace AvaloniaFrontend;

public partial class App : Application
{
    public override void Initialize()
    {
        AvaloniaXamlLoader.Load(this);
    }

    public override void OnFrameworkInitializationCompleted()
    {
        ServiceCollection serviceCollection = new();
        serviceCollection.AddSingleton(serviceCollection);
        serviceCollection.AddSingleton<PageService>();
        serviceCollection.AddSingleton<NavigationService>();

        serviceCollection.AddSingleton<GeneratorViewModel>();
        serviceCollection.AddSingleton<GeneratorPage>();

        serviceCollection.AddSingleton<HomePage>();
        serviceCollection.AddSingleton<HomeViewModel>();

        //TODO #12
        //Add AcquisitionPage and AcquisitionViewModel to serviceCollection as Singletons
        //Also, register the AcquisitionPage 
        serviceCollection.AddSingleton<AcquisitionPage>();
        serviceCollection.AddSingleton<AcquisitionViewModel>();

        PageService pageService = serviceCollection.GetService<PageService>();
        pageService.RegisterPage<GeneratorPage, GeneratorViewModel>("Generator", Material.Icons.MaterialIconKind.SineWave.ToString());
        pageService.RegisterPage<HomePage, HomeViewModel>("Home", Material.Icons.MaterialIconKind.Home.ToString(), showSidePanel: false);
        pageService.RegisterPage<AcquisitionPage, AcquisitionViewModel>("Aquisition page", Material.Icons.MaterialIconKind.Waveform.ToString(), showSidePanel: false);

        NavigationService navigationService = serviceCollection.GetService<NavigationService>();
        navigationService.CurrentPageType = typeof(HomePage);

        if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop)
        {
            desktop.MainWindow = new MainWindow()
            {
                DataContext = serviceCollection.CreateService<MainWindowViewModel>(),
            };
        }

        base.OnFrameworkInitializationCompleted();
    }
}
